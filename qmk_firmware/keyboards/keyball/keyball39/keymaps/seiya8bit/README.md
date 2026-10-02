# seiya8bit keymap for Keyball39

This repository is a fork of [Yowkees/keyball](https://github.com/Yowkees/keyball).
All personal changes live in this directory, and files from upstream are left untouched,
so syncing with upstream never causes conflicts.

## Sync with upstream

Press "Sync fork" on the GitHub repository page, or run:

```sh
gh repo sync seiya8bit/keyball
git pull
```

## Build

Run the "Build a firmware on demand" workflow with keyboard `keyball39` and keymap `seiya8bit`:

```sh
gh workflow run build-user.yml -R seiya8bit/keyball -f keyboard=keyball39 -f keymap=seiya8bit
```

The built firmware is available from the Artifacts of the workflow run.
