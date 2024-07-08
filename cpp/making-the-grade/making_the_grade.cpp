#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> ans;
    for (int score : student_scores) {
        ans.push_back(score);
    }
    return ans;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int ans = 0;
    for (int score : student_scores) {
        if (score <= 40) ans++;
    }
    return ans;
}

// Determine how many of the provided student scores were 'the best' based on the provided threshold.
std::vector<int> above_threshold(std::vector<int> student_scores, int threshold) {
    std::vector<int> ans;
    for (int score : student_scores) {
        if (score >= threshold) ans.push_back(score);
    }
    return ans;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    int inc = (highest_score - 40) / 4;
    std::array<int, 4> ans;
    for (int i = 0; i < ans.size(); i++) {
        ans[i] = 41 + (inc * i);
    }
    return ans;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> ans(student_scores.size(), "");
    for (int i = 0; i < student_scores.size(); i++) {
        ans[i] = std::to_string(i + 1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]);
    }
    return ans;
}

// Create a string that contains the name of the first student to make a perfect score on the exam.
std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names) {
    for (size_t i = 0; i < student_scores.size(); i++) {
        if (student_scores[i] == 100) return student_names[i];
    }
    return "";
}
