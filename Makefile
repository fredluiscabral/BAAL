CXX=g++
CXXFLAGS=-fopenmp -I/home/fred/eigen-3.4.0/ -I/opt/intel/oneapi/mkl/latest/include/
LDFLAGS=-L/opt/intel/oneapi/mkl/latest/lib/ -lmkl_rt
TARGET=Blaol
SRC=main.cpp Matrix.cpp mtx_io.cpp BasicStrategy.cpp EigenSumStrategy.cpp MKLStrategy.cpp
OBJ=$(SRC:.cpp=.o)

$(TARGET): $(OBJ)
    $(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f $(TARGET) $(OBJ)
