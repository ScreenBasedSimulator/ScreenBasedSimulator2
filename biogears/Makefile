CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g -std=c++14 -O3 
MAC_LDFLAGS=-g -lboost_thread-mt -lboost_system-mt -pthread -Wl,-rpath,../lib
INC=-I./include -I./include/cdm -I./include/cdm/bind -I./include/log4cpp/include -I./include/crow
LIBPATH=-L./lib/
MAC_LIBS= ./lib/libxerces-c-3.1.dylib ./lib/CommonDataModelBind.dylib ./lib/CommonDataModel.dylib ./lib/BioGearsEngine.dylib
BIN=./bin

SRCS=./src/Driver.cpp ./src/Connection.cpp ./src/Engine.cpp ./src/Runnable.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

# default:
# 	$(CXX) $(CPPFLAGS) $(LDFLAGS) $(SRCS) $(INC) $(LIBPATH) $(LIBS) -o $(BIN)/Driver

mac:
	$(CXX) $(CPPFLAGS) $(MAC_LDFLAGS) $(SRCS) $(INC) $(LIBPATH) $(MAC_LIBS) -o $(BIN)/BioGearsServer

#all: Driver
#
#Driver: $(OBJS)
#	$(CXX) $(LDFLAGS) -o Driver $(OBJS) $(LIBPATH) $(LIBS)
#
#depend: .depend
#
#.depend: $(SRCS)
#	rm -f ./.depend
#	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;
#
clean:
	$(RM) $(OBJS)
	$(RM) $(BIN)/BioGearsServer
#
#dist-clean: clean
#	$(RM) *~ .depend
#
#include .depend
