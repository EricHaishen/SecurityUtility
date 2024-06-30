# makefile文件只有行注释，不可以在语句后面添加注释

# var for pre-target files 
# chose a compiler
# execute cmd
#OBJS = main_test.o test.o my_stack.o#目标文件依赖文件
#OBJS = *.o  #这里为什么不能在添加了新的c文件后，默认增加新的.o， 目前尚不清楚
CC = gcc
OBJS = main.o test.o pbkdf2.o

#调试过程
CFLAGS += -c -Wall -g   
	
# .o and .c files  每个.o由对应的同名.c生成
%.o:%.c
	$(CC) $^ $(CFLAGS) -o $@

# target file 
my.exe:$(OBJS)
	$(CC) $^ -o $@
	
# clean all the files   windows删除.o文件
clean:
	del my.exe *.o
