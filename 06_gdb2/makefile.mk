src=$(wildcard ./*.cpp)
objs=$(patsubst %.cpp,%.o,$(src))
target=A2
$(target):$(objs)
	$(CXX) $(objs) -o $(target)
%.o:%.cpp
	$(CXX) -c $< -o $@

clean:
	rm $(objs) -f
