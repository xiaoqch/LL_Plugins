import os
import argparse
import project_helper
import shutil

def classify_plugins(build_output_dir, project_root, release_dir):
    shutil.rmtree(release_dir, ignore_errors=True)
    os.makedirs(release_dir)
    plugins = project_helper.get_plugins(build_output_dir)
    for plugin_name in plugins:
        project_dir = os.path.join(project_root, plugin_name)
        if not os.path.exists(project_dir):
            continue
        plugin_version = project_helper.get_project_version(project_dir)
        if not plugin_version:
            continue
        plugin_release_dir = os.path.join(release_dir, f"{plugin_name}-{plugin_version}")
        if not os.path.exists(plugin_release_dir):
            os.makedirs(plugin_release_dir)
        # copy
        dll_path = os.path.join(build_output_dir, f"{plugin_name}.dll")
        if not os.path.exists(dll_path):
            print(f"{dll_path} not found")
            continue
        shutil.copy(dll_path, plugin_release_dir)
        pdb_path = os.path.join(build_output_dir, f"{plugin_name}.pdb")
        if os.path.exists(pdb_path):
            pdb_output_dir = os.path.join(plugin_release_dir, plugin_name)
            os.makedirs(pdb_output_dir, exist_ok=True)
            shutil.copy(pdb_path, pdb_output_dir)
        print(f"{plugin_name}-{plugin_version} copied")



if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-r',"--release-dir", required=True)
    parser.add_argument('-b',"--build-output-dir", required=False, default="x64\\Release")
    parser.add_argument('-p',"--project-root", required=False, default=".")
    args = parser.parse_args()
    classify_plugins(args.build_output_dir, args.project_root, args.release_dir)