from cx_Freeze import setup, Executable

base = None
executables = [Executable("test.py", base=base)]

packages = []
options = {
    'build_exe': {
        'packages': packages,
    },
}

setup(
    name = "Testing...",
    options = options,
    version = "1",
    description = "Please, work!",
    executables = executables
)