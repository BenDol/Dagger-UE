import os
import sys

def rename_and_replace(root_directory, old_str, new_str):
    """
    1) Recursively finds files in `root_directory` whose name contains `old_str` (case-sensitive) 
       and renames them to contain `new_str` instead.
    2) In .cs, .h, .cpp files, replaces:
       - old_str.upper() + '_API' -> new_str.upper() + '_API'
       - old_str -> new_str (case-sensitive)
    """

    # Collect all file paths first so renaming doesn’t affect the iteration.
    file_paths = []
    for current_root, dirs, files in os.walk(root_directory):
        for f in files:
            file_paths.append(os.path.join(current_root, f))

    for file_path in file_paths:
        dir_name = os.path.dirname(file_path)
        file_name = os.path.basename(file_path)

        # 1. Rename file if it contains old_str
        if old_str in file_name:
            new_file_name = file_name.replace(old_str, new_str)
            new_full_path = os.path.join(dir_name, new_file_name)
            os.rename(file_path, new_full_path)
            file_path = new_full_path
            file_name = new_file_name

        # 2. Check file extension and replace content if needed
        _, ext = os.path.splitext(file_name)
        if ext.lower() in [".cs", ".h", ".cpp"]:
            try:
                with open(file_path, 'r', encoding='utf-8') as f:
                    content = f.read()

                # Replace old_str.upper() + "_API" -> new_str.upper() + "_API"
                content = content.replace(old_str.upper() + "_API", new_str.upper() + "_API")

                # Then replace all occurrences of old_str -> new_str (case sensitive)
                content = content.replace(old_str, new_str)

                with open(file_path, 'w', encoding='utf-8') as f:
                    f.write(content)

            except Exception as e:
                print(f"Error processing file '{file_path}': {e}")


def main():
    if len(sys.argv) != 4:
        print("Usage: python rename_and_replace.py <root_directory> <old_string> <new_string>")
        sys.exit(1)

    # Parse command line arguments
    relative_root = sys.argv[1]
    old_str = sys.argv[2]
    new_str = sys.argv[3]

    # Real root is the current working directory joined with the user-provided path
    real_root = os.path.abspath(os.path.join(os.getcwd(), relative_root))

    # Confirm the resolved path
    print(f"Using root directory: {real_root}")

    rename_and_replace(real_root, old_str, new_str)
    print("Done.")


if __name__ == "__main__":
    main()
