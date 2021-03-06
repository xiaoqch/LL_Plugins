from ast import parse
import project_helper
import argparse
import json
import os
def update_solution_build_version(sloution_dir, build_version):
    project_dirs = project_helper.list_project(sloution_dir)
    for project_dir in project_dirs:
        project_helper.update_build_version(project_dir, build_version)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-v', "--build_version", help="The build version", required=True)
    parser.add_argument('-s', "--sloution_dir", help="The solution directory", required=False, default='.')
    parser.add_argument('-r', "--release", help="The release version", required=False, default='false')
    args = parser.parse_args()
    update_solution_build_version(args.sloution_dir, args.build_version)
    if not args.release.lower() == 'true':
        exit(0)
    release_list_path = os.path.join(args.sloution_dir, "Scripts", "release_list.json")
    with open(release_list_path, 'r') as file:
        release_list = json.load(file)
    for plugin_name in release_list:
        plugin_dir = os.path.join(args.sloution_dir, plugin_name)
        project_helper.update_version_status(plugin_dir, "RELEASE")