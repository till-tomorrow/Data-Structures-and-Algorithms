// Append array of strings on value

const appendValues = (value, appends) => {
  if (appends.length === 0) {
    return value
  }
  return value + appends.join('')
};

text = appendValues('A', ['m', 'azi', 'ng']);

console.log(text); // Amazing
