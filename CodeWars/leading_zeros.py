import argparse
import os

parser = argparse.ArgumentParser()

parser.add_argument("-f",
                    "--folder",
                    nargs = 1,
                    default = os.path.dirname(os.path.realpath(__file__)),
                    help = "This parser specifies which sub-directory you want to affect, relative and absolute path both work.")

mode_group = parser.add_mutually_exclusive_group()
mode_group.add_argument("-p",
                        "--pad",
                        action = "store_true",
                        help = "Only affect files that starts with '#'. Pad one zero after '#'")
mode_group.add_argument("-d",
                        "--delete",
                        action = "store_true",
                        help = "Only affect file that starts with '#0'. Deleter one zero after '#'")

args = parser.parse_args()

def pad_zero(current_directory, file, space_index):
    if not file.startswith('#') or file.index(' ') != space_index:
        return

    new_name = '#0' + file[1:]
    os.rename(os.path.join(current_directory, file), os.path.join(current_directory, new_name))

def delete_zero(current_directory, file, space_index):
    if not file.startswith('#0'):
        return

    new_name = '#' + file[2:]
    os.rename(os.path.join(current_directory, file), os.path.join(current_directory, new_name))

def get_space_index(files):
    space_index = set()
    for file in files:
        if file.startswith('#'):
            space_index.add(file.index(' '))

    return min(space_index) if len(space_index) > 1 else None

def loop_through_directory(directory):
    for current_directory, _, files in os.walk(directory):
        space_index = get_space_index(files)
        for file in files:
            leading_zero = pad_zero if args.pad else delete_zero
            leading_zero(current_directory, file, space_index)

def main():
    if not args.pad and not args.delete:
        print("No specified mode. Exiting...")
        exit(1)

    directory = args.folder
    loop_through_directory(directory)

main()
