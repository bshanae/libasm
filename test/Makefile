LOG=$(info [libasm test] $1)
SILENT=@

SRC_DIR=src
SRC=$(wildcard $(SRC_DIR)/*.c)

INCL=include

OBJ_DIR=obj
OBJ=$(patsubst %.c,%.o,$(addprefix $(OBJ_DIR)/,$(notdir $(SRC))))

EXE=test_libasm

LIBASM_DIR=../main
LIBASM=$(LIBASM_DIR)/libasm.a

CC=clang
CFLAGS=$(addprefix -I , $(INCL)) -arch x86_64
LDFLAGS=-L $(LIBASM_DIR) -l asm -arch x86_64

all: $(EXE)

$(EXE): $(OBJ_DIR) $(OBJ)
	$(call LOG,Linking executable $@)
	$(SILENT) $(CC) $(OBJ) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(call LOG,Compiling C object $<)
	$(SILENT) $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	$(call LOG,Creating folder $@)
	$(SILENT) mkdir $@

clean:
	$(call LOG,Deleting objects)
	$(SILENT) rm -rf $(OBJ_DIR)
	$(call LOG,Deleting library objects)

fclean: clean
	$(call LOG,Deleting objects)
	$(SILENT) rm -rf $(OBJ_DIR)
	$(call LOG,Deleting the executable)
	$(SILENT) rm -f $(EXE)


re: fclean all