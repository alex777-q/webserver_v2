src=$(wildcard ./*.cpp)
objs=$(patsubst %.cp,%.o,$(src))
target=Test1
$(target):$(objs)
	$(CXX) $(objs) -o $(target) -g
%.o:%cpp
	$(CXX) -c $< -o $@ -g
clean:
	rm $(objs) -f
