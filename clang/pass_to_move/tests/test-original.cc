// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

struct A {
  A&& Pass();
};

struct B {
  B& Pass();
};

struct C {
  A a;
};

struct D {
  D&& NotPass();
};

void F() {
  A a1;
  A a2 = a1.Pass();

  B b1;
  B b2 = b2.Pass();

  C c;
  A a3 = c.a.Pass();

  D d1;
  D d2 = d1.NotPass();
}
