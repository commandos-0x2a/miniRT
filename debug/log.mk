LOG_MSG = ft_fprintf(2, "%s:%d "format"\n",__FILE__, __LINE__, \#\#__VA_ARGS__)

LOG_LEVEL ?= ERROR  DEBUG 

ifneq ($(findstring DEBUG,$(LOG_LEVEL)),)
CPPFLAGS += -D'LOG_DEBUG(format, ...)=$(LOG_MSG)'
else
CPPFLAGS += -D'LOG_DEBUG(...)=;'
endif

ifneq ($(findstring INFO,$(LOG_LEVEL)),)
CPPFLAGS += -D'LOG_INFO(format, ...)=$(LOG_MSG)'
else
CPPFLAGS += -D'LOG_INFO(...)=;'
endif

ifneq ($(findstring WARN,$(LOG_LEVEL)),)
CPPFLAGS += -D'LOG_WARN(format, ...)=$(LOG_MSG)'
else
CPPFLAGS += -D'LOG_WARN(...)=;'
endif

ifneq ($(findstring ERROR,$(LOG_LEVEL)),)
CPPFLAGS += -D'LOG_ERROR(format, ...)=$(LOG_MSG)'
else
CPPFLAGS += -D'LOG_ERROR(...)=;'
endif

ifneq ($(findstring FATAL,$(LOG_LEVEL)),)
CPPFLAGS += -D'LOG_FATAL(msg)=$(LOG_MSG)'
else
CPPFLAGS += -D'LOG_FATAL(...)=;'
endif

SRC += debug/log.c
