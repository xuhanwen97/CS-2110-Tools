import sys
import csv
import os
import statistics as st

# Instructions: Use python 3, run the command "gradescopeStats.py <file_name.csv>" where the file is the csv file from
# Gradescope's export grades option.
# Parses the data into question number, median, mean, and standard deviation

# Required Packages:
# sys, csv, os, statistics

# Gets the question keys from the header of the CSV file
def getQuestionKeys(header):
    return header[9:]

# Converts Gradescope question key to question number and point value
def parseQuestionKey(gradescope_key):
    splitKey = gradescope_key.split()
    question_num = splitKey[0][0:-1]
    point_val = float(splitKey[-2][1:])
    return question_num, point_val

# Calculates Median, Mean, and Standard Deviation in percentages, rounded to 2 decimal places
# Inputs: list of all the scores and the total possible score
def calculateStats(all_scores, total_possible_points):
    median = (st.median(all_scores) / total_possible_points) * 100
    mean = (st.mean(all_scores) / total_possible_points) * 100
    std_dev = (st.stdev(all_scores) / total_possible_points) * 100

    round_median = round(median, 2)
    round_mean = round(mean, 2)
    round_std_dev = round(std_dev, 2)

    return round_median, round_mean, round_std_dev

def convertGradescopeGrades(input_filename):

    with open(input_filename, 'r') as input_file:
        input_dictionary = csv.DictReader(input_file)
        student_quiz_totals = []
        question_keys = getQuestionKeys(input_dictionary.fieldnames)
        question_dict = {key: [] for key in question_keys}

        # Goes through each student to get data for individual questions if they have a submission
        for row in input_dictionary:
            if row['Status'] == "Missing":
                continue

            # Calculate student total grade for overall quiz statistics
            quiz_total_score = 0

            for key in question_keys:
                question_score = float(row[key])
                question_dict[key].append(question_score)
                quiz_total_score += question_score

            student_quiz_totals.append(quiz_total_score)

        # output format is: [question_number, median, mean, std_dev]
        output = [["Question Number", "Median", "Mean", "Standard Deviation"]]

        # Parses each question's stats and adds it to the output
        total_possible_score = 0
        for key in question_keys:
            question_num, total_question_points = parseQuestionKey(key)
            # Sometimes there are questions that get 0'd out on the rubric
            if total_question_points == 0:
                output.append([question_num, "n/a", "n/a", "n/a"])
                continue
            median, mean, std_dev = calculateStats(question_dict[key], total_question_points)
            output.append([question_num, median, mean, std_dev])
            total_possible_score += total_question_points

        # Add the stats for total quiz grades
        median, mean, std_dev = calculateStats(student_quiz_totals, total_possible_score)
        output.insert(1, ["Quiz Total", median, mean, std_dev])


        # Builds output file, deleting existing ones if exists
        output_filename = "Parsed_" + input_filename

        try:
            os.remove(output_filename)
        except OSError:
            pass

        with open(output_filename, 'w') as output_file:
            writer = csv.writer(output_file)
            writer.writerows(output)



if __name__ == '__main__':
    # if len(sys.argv) == 1:
    #     print("You can also give filename as a command line argument")
    #     filename = input("Enter Filename: ")
    # else:
    #     filename = sys.argv[1]
    #
    # if not os.path.exists(filename):
    #     print("Invalid file name")
    #     exit()
    #
    # convertGradescopeGrades(filename)
    convertGradescopeGrades("Quiz_5_scores.csv")
    print("Successfully parsed!")
