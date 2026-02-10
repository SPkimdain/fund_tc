a="abasdlfkajadfjakeinkxjdfjaioedsksjskjdksjfei"

d = {}
for k in a:
    if k not in d:
        d[k] = 1
    else:
        d[k]+=1

print(d['y'])  # @violation


a_set = {1,2,3,4,5}
a_set.discard(6)
a_set.remove(6)       # @violation

a_set.clear()
a_set.pop()						# @violation

