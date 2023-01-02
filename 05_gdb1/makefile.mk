src=$(wildcard ./*.cpp)
objs=$(patsubst %.cpp,%.o,$(src))
target=A
$(target):$(objs)
	$(CXX) $(objs) -o $(target) -g
%.o:%.cpp
	$(CXX) -c $< -o $@ -g

clean:
	rm $(objs) -f
