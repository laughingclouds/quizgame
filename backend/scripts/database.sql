-- Database: quizgame

DROP DATABASE IF EXISTS quizgame;

CREATE DATABASE quizgame
    WITH
    OWNER = postgres
    ENCODING = 'UTF8'
    LC_COLLATE = 'en_US.UTF-8'
    LC_CTYPE = 'en_US.UTF-8'
    TABLESPACE = pg_default
    CONNECTION LIMIT = -1;

COMMENT ON DATABASE quizgame
    IS 'database for quiz-game';

-- Table: public.user

DROP TABLE IF EXISTS public."user";

CREATE TABLE IF NOT EXISTS public."user"
(
    id integer NOT NULL DEFAULT nextval('user_id_seq'::regclass),
    name text COLLATE pg_catalog."default" NOT NULL,
    password text COLLATE pg_catalog."default" NOT NULL DEFAULT ''::text,
    score integer NOT NULL DEFAULT 0,
    CONSTRAINT user_pkey PRIMARY KEY (id)
)

TABLESPACE pg_default;

ALTER TABLE IF EXISTS public."user"
    OWNER to postgres;

COMMENT ON TABLE public."user"
    IS 'Store all user information such as, username, password, (highest) score.';

COMMENT ON COLUMN public."user".score
    IS 'Highest score of user';

-- Table: public.category

DROP TABLE IF EXISTS public.category;

CREATE TABLE IF NOT EXISTS public.category
(
    id integer NOT NULL DEFAULT nextval('category_id_seq'::regclass),
    name text COLLATE pg_catalog."default" NOT NULL,
    CONSTRAINT category_pkey PRIMARY KEY (id),
    CONSTRAINT category_name_key UNIQUE (name)
)

TABLESPACE pg_default;

ALTER TABLE IF EXISTS public.category
    OWNER to postgres;

COMMENT ON TABLE public.category
    IS 'Store all question categories';

-- Table: public.option

DROP TABLE IF EXISTS public.option;

CREATE TABLE IF NOT EXISTS public.option
(
    id integer NOT NULL DEFAULT nextval('answer_id_seq'::regclass),
    text text COLLATE pg_catalog."default" NOT NULL,
    CONSTRAINT answer_pkey PRIMARY KEY (id),
    CONSTRAINT answer_text_key UNIQUE (text)
)

TABLESPACE pg_default;

ALTER TABLE IF EXISTS public.option
    OWNER to postgres;

COMMENT ON TABLE public.option
    IS 'Store answers to quiz-questions';

-- Table: public.question

DROP TABLE IF EXISTS public.question;

CREATE TABLE IF NOT EXISTS public.question
(
    id integer NOT NULL DEFAULT nextval('question_id_seq'::regclass),
    "categoryId" integer NOT NULL,
    "answerId" integer NOT NULL,
    "option2Id" integer NOT NULL,
    "option3Id" integer NOT NULL,
    "option4Id" integer NOT NULL,
    text text COLLATE pg_catalog."default" NOT NULL,
    CONSTRAINT question_pkey PRIMARY KEY (id),
    CONSTRAINT question_text_key UNIQUE (text),
    CONSTRAINT "question_answerId_fkey" FOREIGN KEY ("answerId")
        REFERENCES public.option (id) MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION,
    CONSTRAINT "question_categoryId_fkey" FOREIGN KEY ("categoryId")
        REFERENCES public.category (id) MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION,
    CONSTRAINT "question_option2Id_fkey" FOREIGN KEY ("option2Id")
        REFERENCES public.option (id) MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
        NOT VALID,
    CONSTRAINT "question_option3Id_fkey" FOREIGN KEY ("option3Id")
        REFERENCES public.option (id) MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
        NOT VALID,
    CONSTRAINT "question_option4Id_fkey" FOREIGN KEY ("option4Id")
        REFERENCES public.option (id) MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
        NOT VALID
)

TABLESPACE pg_default;

ALTER TABLE IF EXISTS public.question
    OWNER to postgres;

COMMENT ON TABLE public.question
    IS 'Store quiz-questions';

-- Table: public.solved

DROP TABLE IF EXISTS public.solved;

CREATE TABLE IF NOT EXISTS public.solved
(
    "userId" integer NOT NULL,
    "questionId" integer NOT NULL,
    CONSTRAINT "solved_questionId_fkey" FOREIGN KEY ("questionId")
        REFERENCES public.question (id) MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION,
    CONSTRAINT "solved_userId_fkey" FOREIGN KEY ("userId")
        REFERENCES public."user" (id) MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
)

TABLESPACE pg_default;

ALTER TABLE IF EXISTS public.solved
    OWNER to postgres;

COMMENT ON TABLE public.solved
    IS 'Store which users solved which questions';