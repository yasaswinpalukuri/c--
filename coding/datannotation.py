def decode(message_file):
    # Read the content of the file
    with open(message_file, 'r') as file:
        lines = file.readlines()

    # Initialize variables
    pyramid = []
    decoded_words = []

    # Process each line in the file
    for line in lines:
        # Split each line into number and word
        parts = line.split()
        number, word = int(parts[0]), parts[1]

        # Add the word to the pyramid list
        pyramid.append((number, word))

        # If the pyramid is complete, decode the message
        if len(pyramid) == pyramid[-1][0]:
            decoded_words.append(pyramid[-1][1])
            print("decodeed:"+decoded_message)
            pyramid = []

    # Combine the decoded words into a string
    decoded_message = ' '.join(decoded_words)
    return decoded_message

# Example usage
message_file = 'A:\my repo\c--\coding\coding_qual_input.txt'
result = decode(message_file)
print(result)



"""
           1
      /         \
     2           3
   /   \       /   \
  4     5     6     7
 / \   / \   / \   / \
8  9  10 11 12 13 14 15
    
1,3,7,15
"""
