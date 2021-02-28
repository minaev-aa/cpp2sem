unsigned int count_total_mice_amount(Cat* cats, unsigned int n){
  unsigned int sum = 0;
  for (int i = 0; i < n; i++) {
      sum += cats[i].mice_caught;
  }
  return sum;
}