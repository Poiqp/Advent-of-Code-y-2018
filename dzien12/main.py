#Setting up initial state
initial_state = list(".......#..#.#..##......###...###...............")

#Setting up templates
##print(templates[0][4]) #templates[zestaw][znak]; znak(0:4)-schemat; znak(5)-wynik
template_data = open("data.txt", "r")
templates = []
for line in template_data:
    values = line.split()
    temp_val = list(values[0])
    temp_lista = [0,0,0,0,0,0]
    for znak in range(5):
        temp_lista[znak] = temp_val[znak]
    temp_lista[-1] = values[2]
    templates.append(temp_lista)
template_data.close()

#Comparaison function | returns instance or false
def comparaison(start_index, initial_state):
    for instance in range(len(templates)):
        if initial_state[start_index:start_index+5]==templates[instance][0:5]:
            return instance
    return -1

#Plant function | applies template to new gen
def plant(next_gen, instance, start_index):
    new_centre = templates[instance][5]
    next_gen[start_index+2] = new_centre   ##new plant
    return next_gen

#Loop
start_index = 0
next_gen = ['.']*len(initial_state)
instance = -1
looper = 1

##Advancing in generations
for generations in range(0,20):
##looping through one genereation
    while start_index + 5 < len(initial_state):
        instance = comparaison(start_index,initial_state)
        if instance != -1:
            next_gen = plant(next_gen,instance,start_index)
            instance = -1
        start_index += 1
        #initial_state = next_gen

    print("GENERACJA {}".format(looper))
    print ''.join(map(str, next_gen))
    initial_state = next_gen
    next_gen = ['.']*len(initial_state)
    start_index = 0
    looper += 1
