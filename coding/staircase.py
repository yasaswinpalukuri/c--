def create_staircase(nums):
  step = 1
  subsets = []
  while len(nums) != 0:
    if len(nums) >= step:
      subsets.append(nums[0:step])
      nums = nums[step:]
      step += 1
    else:
      return False
      
  return subsets

def create_staircase1(nums):
  while len(nums) != 0:
    step = 1
    subsets = []
    if len(nums) >= step:
      subsets.append(nums[0:step])
      nums = nums[step:]
      step += 1
    else:
      return False

  return subsets


l = [1,2,3,4,5,6,7]
print(create_staircase(l))
print(create_staircase1(l))

print(create_staircase([1,2,3,4,5,6]))
print(create_staircase1([1,2,3,4,5,6]))