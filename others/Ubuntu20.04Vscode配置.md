# ubuntu 20.04配置Vscode

step1: 在打开的文件夹下新建一个.cpp文件

step2： 在工作区下创建cpp文件，按F5执行文件，后点击调试，自动跳转到lanuch.json文件夹下，并将lanuch.json文件进行覆盖

```json
// An highlighted block
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
    {
        "name": "(gdb) Launch",
        "type": "cppdbg",
        "request": "launch",
        "program": "${workspaceFolder}/${fileBasenameNoExtension}.out",
        "args": [],
        "stopAtEntry": false,
        "cwd": "${workspaceFolder}",
        "environment": [],
        "externalConsole": true,
        "MIMode": "gdb",
        "preLaunchTask": "build",
        "setupCommands": [
            {
            "description": "Enable pretty-printing for gdb",
            "text": "-enable-pretty-printing",
            "ignoreFailures": true
            }
        ]
    }
    ]
}
```

step3: 更改task.json文件

```json
{
    // See https://go.microsoft.com/fwlink/?LinkId=733558
    // for the documentation about the tasks.json format
    "version": "2.0.0",
    "tasks": [
    {
    "label": "build",
    "type": "shell",
    "command": "g++",
    "args": ["-g", "${file}", "-std=c++11", "-o", "${fileBasenameNoExtension}.out"]
    }
    ]
}
```

step4: 在所建的.cpp文件中F5运行

[参考](https://blog.csdn.net/fangshuo_light/article/details/123635576)
