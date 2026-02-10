const express = require('express');
const app = express();
const process = require('child_process');
const no_process = require('no_child_process');

app.post('/violation1', (req, res) => {
  const cmd = req.query;
  process.exec(cmd);        //@violation
  process.execSync(cmd)     //@violation

  process.spawn(cmd)
  process.spawnSync(cmd)
  process.execFile(cmd)
  process.execFileSync(cmd)
});

app.post('/violation2', (req, res) => {
  const cmd = req.query;
  process.exec(cmd, { shell: true })         //@violation
  process.execSync(cmd, { shell: true })     //@violation

  process.spawn(cmd, { shell: true })        //@violation
  process.spawnSync(cmd, { shell: true })    //@violation
  process.execFile(cmd, { shell: true })     //@violation
  process.execFileSync(cmd, { shell: true }) //@violation
});

app.post('/violation3', (req, res) => {
  const cmd = req.query;
  process.exec(cmd, { shell: false })         //@violation
  process.execSync(cmd, { shell: false })     //@violation

  process.spawn(cmd, { shell: false })
  process.spawnSync(cmd, { shell: false })
  process.execFile(cmd, { shell: false })
  process.execFileSync(cmd, { shell: false })
});

app.post('/violation4', (req, res) => {
  const cmd = req.query;
  option = { temp: false, shell: true }

  process.spawn(cmd, option)        //@violation
  process.spawnSync(cmd, option)    //@violation
  process.execFile(cmd, option)     //@violation
  process.execFileSync(cmd, option) //@violation
});

app.post('/good1', (req, res) => {
  const cmd = req.query;
  no_process.exec(cmd)
  no_process.execSync(cmd)
  no_process.spawn(cmd)
  no_process.spawnSync(cmd)
  no_process.execFile(cmd)
  no_process.execFileSync(cmd)
});

app.post('/good2', (req, res) => {
  const cmd = req.query;
  no_process.exec(cmd, { shell: true })
  no_process.execSync(cmd, { shell: true })
  no_process.spawn(cmd, { shell: true })
  no_process.spawnSync(cmd, { shell: true })
  no_process.execFile(cmd, { shell: true })
  no_process.execFileSync(cmd, { shell: true })
});

app.post('/good3', (req, res) => {
  const cmd = req.query;
  no_process.exec(cmd, { shell: false })
  no_process.execSync(cmd, { shell: false })
  no_process.spawn(cmd, { shell: false })
  no_process.spawnSync(cmd, { shell: false })
  no_process.execFile(cmd, { shell: false })
  no_process.execFileSync(cmd, { shell: false })
});
