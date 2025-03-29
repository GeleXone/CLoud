# CLoud
My game in C++



Prerequisites 
    for Debian:
        sudo apt install libwayland-dev libxkbcommon-dev xorg-dev wget zip make gcc uuid-dev
        wget https://github.com/premake/premake-core/releases/download/v5.0.0-beta5/premake-5.0.0-beta5-src.zip
        unzip premake-5.0.0-beta5-src.zip
        cd premake-5.0.0-beta5-src
        ./Bootstrap.sh
        sudo cp bin/release/premake5 /usr/local/bin/
    for Windows:
        download premake5.exe and move it to premake folder
        execute GenerateProject.bat