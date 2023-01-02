1.静态库的创建

ar rcs libxxx.a xxx.o xxx.o
r 将文件插入备存文件
c 创建备存文件
s 创建索引

2.静态库的使用

创建（include(xxx.h)/lib(libxxx.a)/xxx.）格式的目录
gcc -c xxx.c -o xxx.o -I ./include -l xxx(libxxx.a中的xxx) -L lib

-I 在哪里找头文件
-l 指定库的名字
-L 在哪里找库
