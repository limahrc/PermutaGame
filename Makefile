APP 	= ./app
INCLUDE = ./include
OBJ 	= ./obj
SRC 	= ./src

all: app


%.o: $(SRC)/%.c
	gcc -c -I $(INCLUDE) $< -o $(OBJ)/$@

app: caixa.o main.o
	gcc $(OBJ)/*.o -lhrc -o $(APP)/exe

run:
	$(APP)/exe

clean:
	rm $(OBJ)/*.o
	rm $(APP)/exe
