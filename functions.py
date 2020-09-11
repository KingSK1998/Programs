#Translator
def translate(phrase):
    translation = ""
    for letter in phrase:
        if letter in "AEIOUaeiou":
            translation = translation + letter
            translation = translation + letter
        else:
            translation = translation + letter
    return translation

print(translate(input("Enter a phrase: ")))