TARGET = time_convert
SRC = time_convert_test.c ../Core/Src/time_convert.c ./Unity/src/unity.c
INCLUDES = -I./Unity/src -I../Core/Inc


$(TARGET) : $(SRC)
	$(CC) $(INCLUDES) $(SRC) -o $(TARGET)


run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
    
