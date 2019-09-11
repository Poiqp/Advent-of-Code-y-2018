import numpy as np
#Find new pointer position
def move_p(l, pos, pos_last):
    new_pos = (pos + ((l[pos]+1) % pos_last)) %pos_last
    return new_pos


#Calculate the expansion of recepies
def expansion(l, pos_a, pos_b):
    val = l[pos_a] + l[pos_b]
    l_expansion = [int(d) for d in str(val)]
    return l_expansion


#Basic setup
recipe = 633601
l = np.zeros(recipe+14, dtype=int)
l[0] = 3
l[1] = 7
pos_a = 0
pos_b = 1
pos_last = 2

#Loop
while pos_last < (recipe+10):
    exp = expansion(l,pos_a,pos_b)
    for a in range(len(exp)):
        l[pos_last] = exp[a]
        pos_last += 1
    pos_a = move_p(l,pos_a,pos_last)
    pos_b = move_p(l,pos_b,pos_last)

print("The score for {} number of recipies is: ".format(recipe))
print(l[recipe:recipe+10])
