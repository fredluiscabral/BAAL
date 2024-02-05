CC=g++
CFLAGS=-fopenmp -I/home/fred/eigen-3.4.0/ -I/opt/intel/oneapi/mkl/latest/include/
LDFLAGS=-L/opt/intel/oneapi/mkl/latest/lib/ -lmkl_rt
TARGET=Blaol
SRCS=main.cpp Matrix.cpp mtx_io.cpp BasicStrategy.cpp EigenSumStrategy.cpp MKLStrategy.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)
