{
    files = {
        [[build\.objs\ficello\windows\x64\release\src\main.cpp.obj]],
        [[bin\ficelloEngine.lib]]
    },
    values = {
        [[C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.32.31326\bin\HostX64\x64\link.exe]],
        {
            "-nologo",
            "-dynamicbase",
            "-nxcompat",
            "-machine:x64",
            "-libpath:bin",
            [[-libpath:C:\Users\ordi2132372\AppData\Local\.xmake\packages\l\libsdl\2.0.20\42621af521d34628a083584cefc78328\lib]],
            [[-libpath:C:\Users\ordi2132372\AppData\Local\.xmake\packages\l\lua\v5.4.4\200aae53e3a8489bb9f8fd764de1b658\lib]],
            "/opt:ref",
            "/opt:icf",
            "ficelloEngine.lib",
            "SDL2main.lib",
            "SDL2.lib",
            "lua.lib",
            "gdi32.lib",
            "user32.lib",
            "winmm.lib",
            "shell32.lib"
        }
    }
}