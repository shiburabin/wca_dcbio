/* -*- c++ -*- ----------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov 

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

// I am able to write it based on lj_cut_coul_cut and I am not using born_matrix method.

#ifdef PAIR_CLASS
// clang-format off
PairStyle(wca_dcbio, PairWCA_DC_BIO);
// clang-format on
#else

#ifndef LMP_PAIR_WCA_DC_BIO_H
#define LMP_PAIR_WCA_DC_BIO_H

#include "pair.h"

namespace LAMMPS_NS {

class PairWCA_DC_BIO : public Pair {
 public:
  PairWCA_DC_BIO(class LAMMPS *);
  virtual ~PairWCA_DC_BIO() override;
  virtual void compute(int, int) override;
  virtual void settings(int, char **) override;
  void coeff(int, char **) override;
  void init_style() override;
  double init_one(int, int) override;
  void write_restart(FILE *) override;
  void read_restart(FILE *) override;
  virtual void write_restart_settings(FILE *) override;
  virtual void read_restart_settings(FILE *) override;
  void write_data(FILE *) override;
  void write_data_all(FILE *) override;
  virtual double single(int, int, int, int, double, double, double, double &) override;
  void *extract(const char *, int &) override;

 protected:
  double cut_lj_global, cut_coul_global;
  double **cut_lj, **cut_ljsq;
  double **cut_coul, **cut_coulsq;
  double **epsilon, **sigma;
  double **lj1, **lj2, **lj3, **lj4, **offset;
  double kappa;    

  virtual void allocate();
};

}    // namespace LAMMPS_NS

#endif
#endif

