set shell := ["fish", "-c"]

default:
    @just build then run

then:
    @echo

build:
    @cd ./src && javac -encoding UTF8 Main.java

[no-exit-message]
run:
    @cd ./src && java -Dfile.encoding=UTF-8 -XX:+UseSerialGC Main

checkout id='':
    @./scripts/checkout {{id}}

[no-exit-message]
judge:
    @./scripts/judge

new *args:
    @./scripts/new {{args}}

archive:
    @./scripts/archive
