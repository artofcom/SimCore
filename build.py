import argparse
import subprocess
import sys


def run(command):
    print(f"\n>>> {command}")

    result = subprocess.run(command, shell=True)

    if result.returncode != 0:
        print("\n❌ FAILED")
        sys.exit(result.returncode)


def build():
    print("\n========== BUILD ==========")

    run("cmake -S . -B build")
    run("cmake --build build --config Release")

def test():
    print("\n========== TEST ==========")

    run("ctest --test-dir build --output-on-failure")

def docker():
    print("\n========== DOCKER ==========")

    ## run("docker build -t simcore .")
    run("docker build --no-cache -t simcore .")
    run("docker run --rm simcore")

def main():
    parser = argparse.ArgumentParser(
        description="SimCore Build Tool"
    )

    parser.add_argument(
        "--build",
        action="store_true",
        help="Configure and build the project",
    )

    parser.add_argument(
        "--test",
        action="store_true",
        help="Run unit tests",
    )

    parser.add_argument(
        "--docker",
        action="store_true",
        help="Build and run Docker container",
    )

    parser.add_argument(
        "--all",
        action="store_true",
        help="Run build, test and docker",
    )

    args = parser.parse_args()

    print("==============================")
    print("      SimCore Build Tool")
    print("==============================")

    if args.build:
        build()

    elif args.test:
        test()

    elif args.docker:
        docker()

    elif args.all:
        build()
        test()
        docker()

    else:
        parser.print_help()
        return

    print("\n==============================")
    print("       BUILD SUCCESS")
    print("==============================")


if __name__ == "__main__":
    main()