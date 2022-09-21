LOG=$(info [libasm] $1)
SILENT=@

SRC=ft_read.nasm \
	ft_strcmp.nasm \
	ft_strcpy.nasm \
	ft_strdup.nasm \
	ft_strlen.nasm \
	ft_write.nasm

SRC_BONUS=ft_atoi_base.nasm \
		  ft_list_push_front.nasm \
		  ft_list_remove_if.nasm \
		  ft_list_size.nasm \
		  ft_list_sort.nasm

SRC_DEBUG=print_i_nl.nasm print_c_nl.nasm

OBJ_DIR=obj

OBJ=$(patsubst %.nasm,%.o,$(addprefix $(OBJ_DIR)/,$(SRC)))
OBJ_BONUS=$(patsubst %.nasm,%.o,$(addprefix $(OBJ_DIR)/,$(SRC_BONUS)))
OBJ_DEBUG=$(patsubst %.nasm,%.o,$(addprefix $(OBJ_DIR)/,$(SRC_DEBUG)))

LIB=libasm.a

all: $(LIB)

$(LIB): $(OBJ_DIR) $(OBJ)
	$(call LOG,Building static library $@)
	$(SILENT) ar rcs $(LIB) $(OBJ)
	$(SILENT) ranlib $(LIB)

$(OBJ_DIR)/%.o: %.nasm
	$(call LOG,Compiling NASM object $<)
	$(SILENT) nasm -f macho64 $< -o $@

$(OBJ_DIR):
	$(call LOG,Creating folder $@)
	$(SILENT) mkdir $@

bonus: $(OBJ_DIR) $(OBJ) $(OBJ_BONUS)
	$(call LOG,Building static library $@)
	$(SILENT) ar rcs $(LIB) $(OBJ) $(OBJ_BONUS)
	$(SILENT) ranlib $(LIB)

debug: $(OBJ_DIR) $(OBJ) $(OBJ_BONUS) $(OBJ_DEBUG)
	$(call LOG,Building static library $@)
	$(SILENT) ar rcs $(LIB) $(OBJ) $(OBJ_BONUS) $(OBJ_DEBUG)
	$(SILENT) ranlib $(LIB)

clean:
	$(call LOG,Deleting objects)
	$(SILENT) rm -rf $(OBJ_DIR)

fclean: clean
	$(call LOG,Deleting objects)
	$(SILENT) rm -rf $(OBJ_DIR)
	$(call LOG,Deleting the library)
	$(SILENT) rm -f $(LIB)


re: fclean all