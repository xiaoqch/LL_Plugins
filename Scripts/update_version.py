import os
import re

def get_project_version(version_path):
    with open(version_path, 'r', encoding='utf-8') as file:
        # #define PLUGIN_VERSION_MAJOR 0
        # #define PLUGIN_VERSION_MINOR 0
        # #define PLUGIN_VERSION_REVISION 1
        # #define PLUGIN_VERSION_IS_BETA true
        major_pattern = r'#define +PLUGIN_VERSION_MAJOR +(?P<major>\d+)'
        minor_pattern = r'#define +PLUGIN_VERSION_MINOR +(?P<minor>\d+)'
        revision_pattern = r'#define +PLUGIN_VERSION_REVISION +(?P<revision>\d+)'
        beta_pattern = r'#define +PLUGIN_VERSION_IS_BETA +(?P<beta>\w+)'
        content = file.read()
        major = re.search(major_pattern, content).group('major')
        minor = re.search(minor_pattern, content).group('minor')
        revision = re.search(revision_pattern, content).group('revision')
        beta = re.search(beta_pattern, content).group('beta')
    return major, minor, revision, beta

def update_project(project_dir, bds_version):
    if isinstance(bds_version, list):
        bds_version = ".".join(bds_version)
    # project_dir = /home/user/Projects/ProjectName
    project_name = os.path.basename(project_dir)
    user_file_path = os.path.join(project_dir, f"{project_name}.vcxproj.user")
    if not os.path.exists(user_file_path):
        return
    with open(user_file_path, 'r', encoding='utf-8') as file:
        # change LocalDebuggerWorkingDirectory
        content = file.read()
        # <LocalDebuggerWorkingDirectory>D:\bds\bedrock-server-1.18.11.01\</LocalDebuggerWorkingDirectory>
        # <LocalDebuggerWorkingDirectory>D:\bds\bedrock-server-{bds_version}\</LocalDebuggerWorkingDirectory>
        pattern = r'<LocalDebuggerWorkingDirectory>(?P<path>.*?)\d+\.\d+\.\d+\.\d+\\?</LocalDebuggerWorkingDirectory>'
        dst = r'<LocalDebuggerWorkingDirectory>\g<path>{bds_version}\\</LocalDebuggerWorkingDirectory>'.format(bds_version=bds_version)
        content = re.sub(pattern, dst, content)
        # write back
    with open(user_file_path, 'w', encoding='utf-8') as file:
        file.write(content)
    print(f"{user_file_path} updated")
    return
    version_path = os.path.join(project_dir, f"version.h")
    major, minor, revision, beta = get_project_version(version_path)
    
    

def update_projects(bds_version):
    if isinstance(bds_version, list):
        bds_version = ".".join(bds_version)
    for project_dir in os.listdir('.'):
        if not os.path.isdir(project_dir):
            continue
        if project_dir.startswith('.'):
            continue
        update_project(project_dir, bds_version)

def update_global(bds_version, ll_version, global_path):
    if isinstance(bds_version, list):
        bds_version = ".".join(bds_version)
    if isinstance(ll_version, list):
        ll_version = ".".join(ll_version)
    with open(global_path, 'r', encoding='utf-8') as file:
        # #define TARGET_BDS_VERSION "1.18.11.01"
        # #define TARGET_LITELOADER_VERSION "2.1.3"
        content = file.read()
        bds_pattern = r'(?P<define>#define +TARGET_BDS_VERSION +)"(?P<bds_version>.*?)"'
        ll_pattern = r'(?P<define>#define +TARGET_LITELOADER_VERSION +)"(?P<ll_version>.*?)"'
        dst = r'\g<define>"{bds_version}"'.format(bds_version=bds_version)
        content = re.sub(bds_pattern, dst, content)
        dst = r'\g<define>"{ll_version}"'.format(ll_version=ll_version)
        content = re.sub(ll_pattern, dst, content)
    with open(global_path, 'w', encoding='utf-8') as file:
        file.write(content)
    print(f"{global_path} updated")

def get_version(global_path):
    with open(global_path, 'r', encoding='utf-8') as file:
        bds_pattern = r'#define TARGET_BDS_VERSION +"(?P<bds_version>.*?)"'
        ll_pattern = r'#define TARGET_LITELOADER_VERSION +"(?P<ll_version>.*?)"'
        content = file.read()
        bds_version = re.search(bds_pattern, content).group('bds_version')
        ll_version = re.search(ll_pattern, content).group('ll_version')
    return bds_version, ll_version

def update_bds_lib(sdk_dir, bds_dir = None):
    if os.path.exists(os.path.join(sdk_dir, 'Lib', 'bedrock_server_api.lib')):
        os.remove(os.path.join(sdk_dir, 'Lib', 'bedrock_server_api.lib'))
        print(f"{os.path.join(sdk_dir, 'Lib', 'bedrock_server_api.lib')} removed")
    if os.path.exists(os.path.join(sdk_dir, 'Lib', 'bedrock_server_var.lib')):
        os.remove(os.path.join(sdk_dir, 'Lib', 'bedrock_server_var.lib'))
        print(f"{os.path.join(sdk_dir, 'Lib', 'bedrock_server_var.lib')} removed")
    if not bds_dir or not os.path.exists(bds_dir):
        print(f"bds dir \"{bds_dir}\" not found or not specified")
        return
    tools_dir = os.path.join(sdk_dir, 'Tools')
    lib_builder_path = os.path.join(tools_dir, 'LibraryBuilder.exe')
    if not os.path.exists(lib_builder_path):
        print(f"{lib_builder_path} not found")
        raise FileNotFoundError(f"{lib_builder_path} not found")
    # LibraryBuilder.exe -o ..\Lib\ "$(LocalDebuggerWorkingDirectory)"
    if bds_dir.endswith('\\'):
        bds_dir = bds_dir[:-1]
    # print(f"{lib_builder_path} -o ..\\Lib\\ \"{bds_dir}\"")
    os.system(f"{lib_builder_path} -o ..\\Lib\\ \"{bds_dir}\"")
    print(f"bds lib updated")

def find_bds_dir(bds_version):
    if isinstance(bds_version, list):
        bds_version = ".".join(bds_version)
    pattern = r'<LocalDebuggerWorkingDirectory>(?P<path>.*?)\d+\.\d+\.\d+\.\d+\\?</LocalDebuggerWorkingDirectory>'
    for project_path in os.listdir('.'):
        if not os.path.isdir(project_path):
            continue
        if project_path.startswith('.'):
            continue
        for project_file in os.listdir(project_path):
            if project_file.endswith(".vcxproj.user"):
                with open(os.path.join(project_path, project_file), 'r', encoding='utf-8') as file:
                    content = file.read()
                    bds_dir_prefix = re.search(pattern, content).group('path')
                    return f"{bds_dir_prefix}{bds_version}\\"
    print(f"bds dir for {bds_version} not found")
    return None

def fetch_sdk():
    script_path = 'LiteLoaderSDK\Tools\SDK-submodule-update.cmd'
    if not os.path.exists(script_path):
        print(f"{script_path} not found")
        raise FileNotFoundError(f"{script_path} not found")
    os.system(f"{script_path}")
    print("SDK fetched")

def update_actions(bds_version):
    if isinstance(bds_version, list):
        bds_version = ".".join(bds_version)
    workflows_path = './.github/workflows/msbuild.yml'
    if not os.path.exists(workflows_path):
        print(f"{workflows_path} not found")
        raise FileNotFoundError(f"{workflows_path} not found")
    with open(workflows_path, 'r', encoding='utf-8') as file:
        content = file.read()
        # BDS_VERSION: 1.18.11.01
        bds_pattern = r'BDS_VERSION: (?P<bds_version>.*?)\n'
        bds_dst = r'BDS_VERSION: {bds_version}\n'.format(bds_version=bds_version)
        content = re.sub(bds_pattern, bds_dst, content)
    with open(workflows_path, 'w', encoding='utf-8') as file:
        file.write(content)
    print(f"{workflows_path} updated")

if __name__ == '__main__':
    # bds_version = input("BDS version: ")
    # ll_version = input("LiteLoader version: ")
    bds_version = "1.19.1.01"
    ll_version = "2.3.0"
    global_path = 'Global\GlobalConfig.h'
    sdk_dir = 'LiteLoaderSDK'

    current_bds_version, current_ll_version = get_version(global_path)
    bds_dir = find_bds_dir(bds_version)
    
    
    if current_bds_version == bds_version and current_ll_version == ll_version:
        print("Version is up to date")
    else:
        if current_ll_version != ll_version:
            print(f"LiteLoader version is not up to date, current: {current_ll_version}, target: {ll_version}")
            update_global(bds_version, ll_version, global_path)
            # fetch_sdk()
        if current_bds_version != bds_version:
            print(f"BDS version is not up to date, current: {current_bds_version}, target: {bds_version}")
            update_global(bds_version, ll_version, global_path)
            update_actions(bds_version)
            update_projects(bds_version)
            update_bds_lib(sdk_dir, bds_dir)
    print("Done")