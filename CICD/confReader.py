#!/usr/bin/env python3

class ConfigReader:

    # Initialazing object
    def __init__(self, filepath):

        # path of the config file / file / map of values / len of file
        self.filepath = filepath
        self.dico = {}
        self.length = self.file_len()
        self.content = []

        with open(self.filepath) as file:
            for num, line in enumerate(file.readlines()):

                # getting content and removing useless characters
                self.content.append(line)
                if ':' in line:
                    newEntry = line.rstrip("\r\n").split(':', 1)
                    self.dico[newEntry[0]] = [num, newEntry[1]]

    # Get a variable from the dictionnary
    def get(self, variable):
        if variable in self.dico:
            return self.dico[variable][1]

    # Set a variable in the dictionnary and replace
    def set(self, variable, value):
        if variable in self.dico:
            self.dico[variable][1] = value

    # write the configuration in the current file
    def write(self):

        # open the file and write configuration
        with open(self.filepath, "w") as file:

            # Search lines to replace
            for num, line in enumerate(self.content):
                writen = False

                # Search in the dictionnary
                for data in self.dico:
                    if self.dico[data][0] == num:
                        file.write(data + ":" + self.dico[data][1] + "\n")
                        writen = True

                # The line isn't a config line
                if writen == False:
                    file.write(line)


    def file_len(self):
        with open(self.filepath) as file:
            for index, line in enumerate(file):
                pass
            return index + 1

    def get_all(self):
        varList = []
        [varList.append(item[1]) for item in self.dico.values()]
        return varList