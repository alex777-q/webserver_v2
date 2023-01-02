src=$(wildcard ./*.cpp)
objs=$(patsubst %.cpp,%.o,$(src))
target=Test
$(target):$(objs)
	$(CXX) $(objs) -o $(target)
%.o: %.cpp
	$(CXX) -c $< -o $@
clean:
	rm $(objs) -f

# %匹配字符串 $< 第一个依赖文件的名称 $@ 目标的完整名称
