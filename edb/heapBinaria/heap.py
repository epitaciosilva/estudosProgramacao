arvore = [None]

def add(value):
    global arvore

    index = 0
    limit = 1
    offset = 0
    
    while index < len(arvore):
        # quando a árvore enche é preciso alocar mais espaço
        if index == len(arvore)-1:
            arvore += (None, None)
        # como é binário, quando o limit chega a 3 é pq offset(nó/pai) já tem duas folhas
        if limit == 3:
            offset +=1
            limit = 1
        # adicionando
        if arvore[index] == None:
            arvore[index] = value
            break
        else:
            index = offset*2+limit
            limit += 1
    
for i in range(3):
    add(i)
print(arvore)

# def append(value):
#     global arvore

#     if len(arvore) == 0:
#         arvore += (value,0,0)
#     else:
#         idx = 0
#         while idx < len(arvore):
#             if value < arvore[idx]:
#                 if idx*2+2 < len(arvore) and arvore[idx*2+2] == 0:
#                     arvore[idx*2+2] = arvore[idx]
#                     arvore[idx] = value
#                     arvore += (0,0)
#                     break
#                 elif idx*2+1 < len(arvore) and arvore[idx*2+1] == 0:
#                     arvore[idx*2+1] = arvore[idx]
#                     arvore[idx] = value
#                     arvore += (0,0)
#                     break
#             idx +=1