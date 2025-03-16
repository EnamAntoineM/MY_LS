/*
** MY_PROJECT (IDEA FROM EPITECH), 2025
** sorting.cpp
** MY_LS
** Author: Enam KODJOH-KPAKPASSOU
** Email: eakodjoh-kpakpassou@st.ug.edu.gh
** File description:
*/


// 1. Function to convert a string to lowercase
std::string toLower(const std::string& str)
{
    std::string lowerStr = str; // Make a copy of the input string
    // Transform each character to lowercase in-place:
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr; // Return the new lowercase string
}

// 2. Function to perform a case-insensitive sort that preserves the original case
void regsort(std::vector<std::string>& files)
{
    // Make a copy of the original list; this will hold the lowercase versions.
    std::vector<std::string> lowerFiles = files;
    // Create a vector of indices with the same size as files.
    std::vector<int> indices(files.size());

    // Initialize lowerFiles (convert each string to lowercase) and record the original indices.
    for (size_t i = 0; i < files.size(); i++) {
        lowerFiles[i] = toLower(files[i]); // Convert file name to lowercase
        indices[i] = i;                    // Initially, indices are in order: 0, 1, 2, ...
    }
    // Sort the indices based on the lowercase strings.
    std::sort(indices.begin(), indices.end(), [&](int a, int b) {
        // Compare the lowercase version of the strings at positions a and b.
        return lowerFiles[a] < lowerFiles[b];
    });
    // Create a new vector to store the sorted original strings.
    std::vector<std::string> sortedFiles(files.size());
    for (size_t i = 0; i < files.size(); i++) {
        // Use the sorted indices to rearrange the original strings.
        sortedFiles[i] = files[indices[i]];
    }
    // Replace the original vector with the sorted vector.
    files = sortedFiles;
}
