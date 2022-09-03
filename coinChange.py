coins = [1, 5, 8]
change = 12


def removeDuplicates(combos):
  filtered = set()
  for combo in combos:
    combo.sort()
    filtered.add(tuple(combo))
  return [list(i) for i in filtered]


def coin_change(c):
  if c == 0:
    return [[]]
  if c < 0:
    return []
  else:
    all_combos = []
    for i in coins:
      recursive_result = coin_change(c-i)
      for combo in recursive_result:
        combo.append(i)
      all_combos.extend(recursive_result)

    return removeDuplicates(all_combos)


result = coin_change(change)
result.sort(key=len)
print(result)

print(result[0])
