APP 		= ./app
INCLUDE = ./include
OBJ 		= ./obj
SRC 		= ./src

all: app
	echo ':: pronto para executar'

%.o: $(SRC)/%.c
	@gcc -c -I $(INCLUDE) $< -o $(OBJ)/$@
	@echo ':: arquivo objeto gerado:' $@

app: caixa.o main.o
	gcc $(OBJ)/*.o -o $(APP)/exe
	echo ':: executável gerado'

run:
	$(APP)/exe

clean:
	rm $(OBJ)/*.o
	rm $(APP)/exe
	echo ':: limpeza concluída'

.SILENT: all app run clean
