String putZero(int number)
{
  if (number < 10)
  {
    return ("0" + String(number));
  }
  return String(number);
}