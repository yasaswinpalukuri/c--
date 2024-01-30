def decode_with_numbers(message_file):
    print("Data annotation assignment:")
    with open(message_file, 'r') as file:
        lines = file.readlines()

    pyramid = []
    decoded_sequence = []

    for line in lines:
        parts = line.split()
        number, word = int(parts[0]), parts[1]

        pyramid.append((number, word))
        # print(pyramid)

        if len(pyramid) == pyramid[-1][0]:
            decoded_sequence.extend(pyramid)
            pyramid = []
    
    # print("Pyramid:"+ str(pyramid))
    print("Decode sequence:"+ str(decoded_sequence))

"""def decode_with_numbers(message_file):
    with open(message_file, 'r') as file:
        lines = file.readlines()

    decoded_sequence = []
    current_position = 1

    for line in lines:
        parts = line.split()
        number, word = int(parts[0]), parts[1]

        if number == current_position:
            decoded_sequence.append((number, word))
            current_position += 1

    print(decoded_sequence)"""
# Example usage
message_file = 'A:\my repo\c--\coding\dataAnnotationTextFile.txt'
decode_with_numbers(message_file)


