# Python code to Reverse each word 
# of a Sentence individually

# Package for Regular Expression Comparison
import re

# Check whether string is pure alphabetically or contain special character
def check(text):
    regex = re.compile('[@_!#$%^&*()<>?/\|}{~:.]')
    if(regex.search(text) == None):
        return True
    else:
        return False

# Rever the String
def mirror(a):
    return a[::-1]

# Iterate till Special Character, form the Word from characters appended, reverse it and append the character at same position
def reverse(text):
    TEMP = list(text)
    LENGTH = len(TEMP)
    CHARA = []
    TOTAL = []    
    for i in range(LENGTH):
        if not (check(TEMP[i])):
            if(len(CHARA) == 0):
                CHARA.append(TEMP[i])
            else:
                TOTAL.append(mirror(''.join(CHARA)))
                TOTAL.append(TEMP[i])
                CHARA[:] = []
        else: 
            CHARA.append(TEMP[i])
            
    if not (len(CHARA) == 0):
        TOTAL.append(mirror(''.join(CHARA)))
        
    return ''.join(TOTAL)
    
# Function to Reverse words 
def reverseWordSentence(Sentence): 

	# Spliting the Sentence into list of words. 
	words = Sentence.split(" ") 
	
	# Reversing each word and creating 
	# a new list of words 
	# List Comprehension Technique 
	newWords = [reverse(word) for word in words] 
	
	# Joining the new list of words 
	# to for a new Sentence 
	newSentence = " ".join(newWords) 

	return newSentence 

# Driver's Code 
Sentence = "We are at Inginite Solutions! Their email-id is careers@ignitesol.com"
# Calling the reverseWordSentence 
# Function to get the newSentence 
print(reverseWordSentence(Sentence))
