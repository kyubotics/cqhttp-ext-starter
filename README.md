# cqhttp-ext-starter

[![License](https://img.shields.io/badge/license-MIT%20License-blue.svg)](LICENSE)

用于编写 CoolQ HTTP API 插件扩展的 starter 工程。

## 使用方式

首先克隆 [richardchien/coolq-http-api](https://github.com/richardchien/coolq-http-api) 项目，并配置它的构建环境（成功运行 `scrips/prepare.ps1`），最好再检查一下是否确实能够成功构建。

然后在 **`coolq-http-api` 所在目录**中，克隆本项目（也就是说 `cqhttp-ext-starter` 和 `coolq-http-api` 平级），使用 VS 打开本 starter 工程，在 [`src/main.cpp`](src/main.cpp) 基础上修改即可。

代码编写完成后直接使用菜单栏的 CMake - 全部生成 来构建，成功后将 `build\Debug\Debug\`（如果是 release 版本则在 `build\Release\Release\`）中的相应 DLL 文件复制到 酷Q 的 `data\app\io.github.richardchien.coolqhttpapi\extensions\`（如果没有则创建）中，设置插件配置项 `use_extension = true`，重启插件即可。

注意，debug 版本的扩展必须配合 debug 版本的插件使用，release 同理。
