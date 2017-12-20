#!/usr/bin/env python3

import random
import time

def main():
   # Prompt for numbers
   numbers = _promptNumbers()
   # Start sorting
   print('Starting bogosort...')
   print('-'*80)     
   start = time.time()
   n = 0
   while True:
      if n != 0:
         # Shuffle numbers
         random.shuffle(numbers)
      print('#%s: %s' % (n, numbers))
      # Check if numbers are sorted
      if _isSorted(numbers):
         break
      n += 1 
   # End sorting
   end = time.time()
   print('-'*80)
   print('Bogosort completed for %s elements.' % len(numbers))
   print('Shuffles done: %s' % _formatShuffles(n))
   print('Time elapsed : %s' % _formatTime(end-start))

def _promptNumbers(prompt='Numbers (Use space):', error='Invalid input.', 
   test=False):
   '''
   -> list -> List of int for numbers
   '''
   while True:
      print(prompt)
      ns = input('')
      try:
         ns = list(map(lambda n: int(n.strip()), ns.split()))
         # There must be more than one number given
         if len(ns) <= 1:
            raise ValueError
      except ValueError: 
         print(error+'\n')
         if test:
            break
      else:
         return ns

def _isSorted(list):
   '''
   -> True  : List of integers is sorted 
   -> False : List of integers is unsorted
   '''
   for i in range(len(list)-1):
      if list[i] > list[i+1]:
         return False
   return True

def _formatShuffles(integer):
   '''
   -> str: Formatted number of shuffles (1,000,000)
   '''
   integer = str(integer)
   string = []
   n = 0
   for i in range(len(integer)-1, -1, -1):
      if n == 3:
         string.append(',')
         n = 1
      else: 
         n += 1
      string.append(integer[i])
   string.reverse()
   return ''.join(string)

def _formatTime(seconds):
   '''
   -> str: Formatted time (2h 10m 40s)
   '''
   seconds = round(seconds)
   if seconds < 60:
      return '%ss' % seconds
   else:
      minutes = seconds // 60
      seconds = seconds % 60
      if minutes < 60:
         return '%sm %ss' % (minutes, seconds)
      else:
         hours = minutes // 60
         minutes = minutes % 60
         return '%sh %sm %ss' % (hours, minutes, seconds)

if __name__ == '__main__':
   main()