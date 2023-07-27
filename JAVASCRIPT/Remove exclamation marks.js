/*
Write function RemoveExclamationMarks which removes all exclamation marks from a given string.
*/
function removeExclamationMarks(s) {
  return s.replaceAll('!', '');
}

// ALTERNATIVE USING REGEX
//  return s.replace(/!/g, '');
