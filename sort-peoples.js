const peoples = [
  { name: 'Paulo', age: 19 },
  { name: 'Hannah', age: 26 },
  { name: 'Lucio', age: 32 },
  { name: 'Waldo', age: 73 },
  { name: 'Larissa', age: 22 },
  { name: 'Brucer', age: 15 }
];

const sortNames = peoples.sort((a, b) => {
  const firstName = a.name.toLowerCase();
  const secondName = b.name.toLowerCase();
  if (firstName < secondName) return -1
  if (firstName > secondName) return 1
  return 0
})

console.log(sortNames);
