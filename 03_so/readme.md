
一 动态库的制作
1.g++ 得到 .o文件，得到和位置无关的代码

g++ -c -fpic/-fPIC xxx.cpp
-fpic参数主要发生在编译->汇编的过程中

2.g++c 得到动态库

g++ -shared xxx.o -o libxxx.so
.so 文件在linux下为可执行文件

二 使用动态库
1.参照静态库的使用方法输入

g++ xxx.cpp -o xxx -I ./inlcude/ -l xxx -L lib/
[如果使用的是gcc，对于动态库而言，链接时，动态库代码不会被打包到可执行文件中]
[程序启动之后，动态库会被动态加载到内存中]

我们可以通过ldd命令来检查动态库的依赖关系  ——ldd xxx


