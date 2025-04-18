import random
import math

# Returns function values to Array
def myFunction(x):
    if (x == 0):
        return 0
    elif ((math.log2(x) * 7)% 17) < (x % 13):
        y = round((x + math.log2(x))**3,1)
        return y
    elif ((math.log2(x)* 5)%23) < (x % 19):
        y = round((math.log2(x)*2)**3, 1)
        return y
    else:
        y = round((math.log2(x)**2)- x, 1)
        return y

def hillClimb(arr, start_index):
    # Created local variables based on parameters
    current_index = start_index
    current_value = arr[current_index]

    # Finds value of the indexes before and after current value and compares them.
    while True:
        left_index = current_index - 1 if current_index > 0 else None
        right_index = current_index + 1 if current_index < len(arr) - 1 else None

        left_value = arr[left_index] if left_index is not None else None
        right_value = arr[right_index] if right_index is not None else None
        # Increases index by 1 if both the left value and right value are greater than current value.
        if left_value is not None and left_value > current_value and right_value is not None and right_value > current_value:
            current_index += 1
        # Changes current value to the left value if left value is greater and right isn't
        elif left_value is not None and left_value > current_value:
            current_index -= 1
        # Same as above except right replaces current
        elif right_value is not None and right_value > current_value:
            current_index += 1
        # if no value is greater, break out of loop
        else:
            break
        # Redefines current value with new current index
        current_value = arr[current_index]
    return current_index, current_value


def main():
    # Create array and define attempts and local max
    arr = [myFunction(x) for x in range(10000)]
    attempts = 10
    best_local_max = float('-inf')

    # for loop based on number of attempts
    for _ in range(attempts):
        # Receives random index to use as parameter for function hillClimb
        start_index = random.randint(1, 9998)
        local_max_index, local_max_value = hillClimb(arr, start_index)
        # if returned value is greater than defined max, redefine the best local max
        if local_max_value > best_local_max:
            best_local_max = local_max_value
    # Get max from array using function max and store it
    global_max = max(arr)
    # Output statement that states whether we got actual max or not based on attempts.
    print(
        f"After {attempts} tries, the greatest local maximum discovered was {best_local_max}. The actual global maximum was {global_max}.")


if __name__ == "__main__":
    main()