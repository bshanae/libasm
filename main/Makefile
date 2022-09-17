LOG=$(info [libasm] $1)
SILENT=@

SRC=$(wildcard *.nasm)

OBJ_DIR=obj
OBJ=$(patsubst %.nasm,%.o,$(addprefix $(OBJ_DIR)/,$(SRC)))

LIB=libasm.a

all: $(LIB)

$(LIB): $(OBJ_DIR) $(OBJ)
	$(call LOG,Building static library $@)
	$(SILENT) ar rcs $(LIB) $(OBJ)
	$(SILENT) ranlib $(LIB)

$(OBJ_DIR)/%.o: %.nasm
	$(call LOG,Compiling NASM object $<)
	$(SILENT) nasm -felf64 $< -o $@

$(OBJ_DIR):
	$(call LOG,Creating folder $@)
	$(SILENT) mkdir $@

clean:
	$(call LOG,Deleting objects)
	$(SILENT) rm -rf $(OBJ_DIR)

fclean: clean
	$(call LOG,Deleting objects)
	$(SILENT) rm -rf $(OBJ_DIR)
	$(call LOG,Deleting the library)
	$(SILENT) rm -f $(EXE)


re: fclean all