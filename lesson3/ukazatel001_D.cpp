int* now_get_me_some_bytes(unsigned int n){
  int* a = new int[n];
  return a;
}

void now_free_some_bytes(int* p){
  delete[] p;
}