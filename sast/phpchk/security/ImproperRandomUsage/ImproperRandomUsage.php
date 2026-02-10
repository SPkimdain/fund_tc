<?php
  echo rand(); // @violation
  echo rand(5, 15); // @violation

  echo mt_rand(); // @violation
  echo mt_rand(5, 15); // @violation

