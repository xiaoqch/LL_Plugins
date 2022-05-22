import os
import re
import shutil

def is_project_dir(dir_name):
    if not os.path.isdir(dir_name):
        return False
    project_name = os.path.basename(dir_name)
    project_file_path = os.path.join(dir_name, f"{project_name}.vcxproj")
    return os.path.exists(project_file_path)


def list_project(sloution_dir):
    project_dirs = []
    for file_name in os.listdir(sloution_dir):
        file_path = os.path.join(sloution_dir, file_name)
        if is_project_dir(file_path):
            project_dirs.append(file_path)
    return project_dirs


def get_project_version(project_dir):
    # #define PLUGIN_VERSION_MAJOR 0
    # #define PLUGIN_VERSION_MINOR 0
    # #define PLUGIN_VERSION_REVISION 1
    # #define PLUGIN_VERSION_IS_BETA false
    version_path = os.path.join(project_dir, "version.h")
    if not os.path.exists(version_path):
        return None
    with open(version_path, 'r', encoding='utf-8') as file:
        # #define PLUGIN_VERSION_MAJOR 0
        # #define PLUGIN_VERSION_MINOR 0
        # #define PLUGIN_VERSION_REVISION 1
        # #define PLUGIN_VERSION_STATUS       PLUGIN_VERSION_DEV
        major_pattern = r'#define +PLUGIN_VERSION_MAJOR +(?P<major>\d+)'
        minor_pattern = r'#define +PLUGIN_VERSION_MINOR +(?P<minor>\d+)'
        revision_pattern = r'#define +PLUGIN_VERSION_REVISION +(?P<revision>\d+)'
        beta_pattern = r'#define +PLUGIN_VERSION_STATUS +PLUGIN_VERSION_(?P<status>\w+)'
        content = file.read()
        major = re.search(major_pattern, content).group('major')
        minor = re.search(minor_pattern, content).group('minor')
        revision = re.search(revision_pattern, content).group('revision')
        status = re.search(beta_pattern, content).group('status')
        return f"{major}.{minor}.{revision}{'b' if status != 'RELEASE' else ''}"

def update_build_version(project_dir, build_version):
    version_path = os.path.join(project_dir, "version.h")
    if not os.path.exists(version_path):
        return
    with open(version_path, 'r', encoding='utf-8') as file:
        content = file.read()
    content = re.sub(r'(?P<define>#define +PLUGIN_VERSION_BUILD +)(?P<version>\d+)', f"\\g<define>{build_version}", content)
    with open(version_path, 'w', encoding='utf-8') as file:
        file.write(content)

def update_version_status(project_dir, status):
    # #define PLUGIN_VERSION_STATUS       PLUGIN_VERSION_DEV
    status = status.upper()
    version_path = os.path.join(project_dir, "version.h")
    if not os.path.exists(version_path):
        return
    with open(version_path, 'r', encoding='utf-8') as file:
        content = file.read()
    content = re.sub(r'(?P<define>#define +PLUGIN_VERSION_STATUS +PLUGIN_VERSION_)(?P<status>\w+)', f"\\g<define>{status}", content)
    with open(version_path, 'w', encoding='utf-8') as file:
        file.write(content)

def get_plugins(output_dir):
    plugins = []
    for file_name in os.listdir(output_dir):
        file_path = os.path.join(output_dir, file_name)
        if os.path.isdir(file_path):
            continue
        if file_name.endswith(".dll"):
            plugins.append(file_name[: -4])
    return plugins

def add_build_version(project_dir):
    # #define PLUGIN_VERSION_REVISION 1
    # add "#define PLUGIN_VERSION_BUILD 0" after
    version_path = os.path.join(project_dir, "version.h")
    if not os.path.exists(version_path):
        return
    with open(version_path, 'r', encoding='utf-8') as file:
        content = file.read()
    content = re.sub(r'#define PLUGIN_VERSION_REVISION (?P<revision>\d+)', r'#define PLUGIN_VERSION_REVISION \g<revision>\n#define PLUGIN_VERSION_BUILD 0', content)
    with open(version_path, 'w', encoding='utf-8') as file:
        file.write(content)


if __name__ == '__main__':
    update_version_status("OperationAgent", "RELEASE")
    pass
